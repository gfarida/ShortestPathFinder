import os
import subprocess
import pytest

TEST_DIR = "tests/pytest"
EXECUTABLE = "./minPathLen"

test_files = [
    f for f in os.listdir(TEST_DIR) if not f.endswith(".out")
]

@pytest.mark.parametrize("test_name", test_files)
def test_minpathlen(test_name):
    test_file = os.path.join(TEST_DIR, test_name)
    expected_output_file = f"{test_file}.out"
    actual_output_file = f"{test_file}.out.tmp"

    with open(actual_output_file, "w") as out:
        subprocess.run([EXECUTABLE, test_file], stdout=out)

    with open(expected_output_file, "r") as expected, open(actual_output_file, "r") as actual:
        expected_output = expected.read().strip()
        actual_output = actual.read().strip()

    os.remove(actual_output_file)

    assert actual_output == expected_output, (
        f"Test failed: {test_name}\n"
        f"Expected output:\n{expected_output}\n"
        f"Actual output:\n{actual_output}"
    )