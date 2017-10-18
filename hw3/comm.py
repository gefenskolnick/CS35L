#!/usr/bin/python 
import string
import sys
import locale 
from optparse import OptionParser


def rawComm(file1, file2, arg1, arg2, arg3):
    tmp = []
    while len(file1) != 0 or len(file2) != 0:
        if len(file2) == 0 or (len(file1) != 0 and file1[0] < file2[0]):
            if not arg1:
                tmp.append(file1[0])
            file1.remove(file1[0])
        elif len(file1) == 0 or (len(file2) != 0 and file1[0] > file2[0]):
            if not arg2:
                tmp.append((1-arg1)*"\t" + file2[0])
            file2.remove(file2[0])
        else: # file1[0] == file2[0]
            if not arg3:
                tmp.append((2-arg1-arg2)*"\t"+file1[0])
            file1.remove(file1[0])
            file2.remove(file2[0])
    return tmp


def unsortComm(file1, file2, arg1, arg2, arg3):
    tmp = []
    for l1 in file1:
        for l2 in file2:
            if l1 == l2:
                if not arg3:
                    tmp.append((2-arg1-arg2)*"\t"+l1)
                file2.remove(l2)
                break
        else: #correspond to l1 == l2
            if not arg1:
                tmp.append(l1)
    if not arg2:
        for l2 in file2:
            tmp.append((1-arg1)*"\t"+l2)
    return tmp


def main():
    locale.setlocale(locale.LC_COLLATE, 'C')
    usage_msg = """%prog [OPTION]... FILE1 FILE2 Output three columns, containing lines only in FILE1, lines only in FILE2, and lines in both files."""
    parser = OptionParser(usage=usage_msg)
    parser.add_option("-1", action='store_true', dest="arg1", help="suppress first column of output")
    parser.add_option("-2", action='store_true', dest="arg2", help="suppress second column of output")
    parser.add_option("-3", action='store_true', dest="arg3", help="suppress third column of output")
    parser.add_option("-u", action='store_true', dest="argu", help="allow input of unsorted files")
    options, args = parser.parse_args(sys.argv[1:])
    if len(args) != 2:
        parser.error("Wrong number of operands!")
    if args[0] == "-":
        inputfile1 = sys.stdin.readlines()
    else:
        f = open(args[0], 'r')
        inputfile1 = f.readlines()
        f.close()
    if args[1] == "-":
        inputfile2 = sys.stdin.readlines()
    else:
        f = open(args[1], 'r')
        inputfile2 = f.readlines()
        f.close()
    if bool(options.argu):
        rawData = unsortComm(inputfile1, inputfile2, bool(options.arg1), bool(options.arg2), bool(options.arg3))
    else:
        rawData = rawComm(inputfile1, inputfile2, bool(options.arg1), bool(options.arg2), bool(options.arg3))
    out = ''.join(rawData)
    sys.stdout.write(out)


if __name__ == "__main__":
    main()
