import params
import ctypes

splash_lib = ctypes.CDLL('./splash.so')
params = [
    'splahs',
    '/home/administrateur/splash_mem/pl/p1.so',
    '/home/administrateur/splash_mem/pl/p2.so',
    '/home/administrateur/splash_mem/pl/p3.so',
    '/home/administrateur/splash_mem/pl/p4.so'
]
argv = (ctypes.POINTER(ctypes.c_char)*(len(params)+1))()

for i, arg in enumerate(params):
    emc_arg = arg.encode('utf-8')
    argv[i]= ctypes.create_string_buffer(emc_arg)

splash_lib.main(len(params))