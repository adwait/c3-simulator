from simics import *

import subprocess
import os

def command_to_console(cmd, nofail=False):
    # Fixes at least some crashes with missed return values
    if len(cmd) == 62:
        cmd = cmd + " "
    run_command("$con.input \"" + cmd + "\n\"")
    run_command("bp.console_string.wait-for $con \"$ \"")

    # Test for zero return code
    run_command("$con.record-start")
    run_command("$con.input \"echo $?\n\" ") # Echo the return code of the last command
    run_command("bp.console_string.wait-for $con \"$ \"")
    res = int(strip_anci(run_command("$con.record-stop")).splitlines()[-2]) # Get output, Remove ANCI colorcodes, get second line, format as Integer.
    if res != 0 and not nofail:
        if simenv.exit == 1:
            print("Console command \"" + cmd + "\" returned code " + str(res) + ".\nTerminating simulation (due exit=1).")
            sys.exit(2)
        raise Exception("Console command \"" + cmd + "\" returned code " + str(res) + ". Script halted.")
    return res


def recompile(file_name):
    # Compile file
    command_to_console(f"g++ -g -gdwarf -Werror -ldl -lm -lpthread -pthread -Iinclude -o a.out {file_name}")

def recompile_local(file_name):
    # Compile file
    subprocess.Popen(["clang++", f"microbenchmarks/{file_name}", "-o", "a.out"], cwd=os.getcwd()).wait()

def rerun():
    # Run file
    command_to_console(f"CC_ENABLED=1 ./a.out")