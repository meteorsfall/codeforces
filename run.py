import subprocess
import sys

script_path = 'A.py'
input_file_path = 'raw_input'

def main():
    if len(sys.argv) < 2:
        print("Usage: python run.py <script_name>")
        sys.exit(1)

    # Script to run is the first command-line argument
    script_path = sys.argv[1]
    input_file_path = 'raw_input'

    # Check if the input file exists
    try:
        # Open the input file
        with open(input_file_path, 'rb') as input_file:
            # Run the script and pass the file's content to its stdin
            process = subprocess.Popen(['python', script_path], stdin=input_file, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

            # Wait for the process to complete and get the output
            stdout, stderr = process.communicate()

    except FileNotFoundError:
        print(f"Error: The file {input_file_path} does not exist.")
        sys.exit(1)

    # Output results
    if process.returncode != 0:
        print("Error running script:")
        print(stderr.decode())
    else:
        print("Output from the script:")
        print(stdout.decode())

if __name__ == "__main__":
    main()