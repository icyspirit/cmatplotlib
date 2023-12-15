#!/usr/bin/env python


from builtins import *
from matplotlib.pyplot import *
from numpy import *
import types


forbidden = [
    'bool',
    'float',
    'int',
    'short',
    'double',
    'void',
    'typename',
    'delete',
]


with open("genfunc.hpp", 'w') as f:
    for key, func in dict(globals()).items():
        if callable(func):
            if key not in forbidden:
                f.write(f"GENFUNC({key})\n")

