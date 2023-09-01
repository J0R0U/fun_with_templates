# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

import cv2
import sys
import os

# The input file
inFile = sys.argv[1]

# Check if an output file is given
if len(sys.argv) > 2:
    outFile = sys.argv[2]
else:
    outFile = os.path.splitext(inFile)[0] + ".png"

# Read the input file
img = cv2.imread(inFile)

# Write the output file
cv2.imwrite(outFile, img)
