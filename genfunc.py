#!/usr/bin/env python


import matplotlib.pyplot


with open("genfunc.hpp", 'w') as f:
    for key in dir(matplotlib.pyplot):
        if callable(getattr(matplotlib.pyplot, key)):
            f.write(f"GENFUNC({key})\n")

