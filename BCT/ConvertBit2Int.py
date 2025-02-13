import sys

size = 2

while True:
    line = sys.stdin.readline().replace("\n", "")
    nums = [line[x:x+size] for x in range(0, len(line), size)]

    count = 0
    while len(nums) > 0 and nums[0] == "10":
        nums.pop(0)
        count += 1

    if nums == ["01"]: print(count)
