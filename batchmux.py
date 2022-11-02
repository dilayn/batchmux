# Name and open the script file
file = input("TV Show name: ") + ".sh"
file = open(file, "wt")

# Specify number of episodes
i = int(input("Number of episodes: ")) + 1

# Input the mkvmerge command
command = input("Input command: ")

# Bash script header
file.write("#!/bin/bash" + "\n")

# Episode count is less than 100
if i < 101:
    for i in range(1, i):
        ep = str(i)
        file.write(command.replace("XX", ep.zfill(2)) + "\n")

# Episode count is more than 100
elif i >= 101:
    for i in range(1, i):
        ep = str(i)
        file.write(command.replace("XX", ep.zfill(3)) + "\n")

file.close()
