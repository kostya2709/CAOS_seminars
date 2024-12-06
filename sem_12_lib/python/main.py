import ctypes

dl = ctypes.cdll.LoadLibrary("libdynamic.so")
dl.hello()

