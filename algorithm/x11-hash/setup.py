from setuptools import setup, Extension

x11_hash_module = Extension('x11_hash',
                            sources = ['x11module.c',
                                       'x11.c',
                                       '../../sph/blake.c',
                                       '../../sph/bmw.c',
                                       '../../sph/groestl.c',
                                       '../../sph/skein.c',
                                       '../../sph/jh.c',
                                       '../../sph/keccak.c',
                                       '../../sph/luffa.c',
                                       '../../sph/cubehash.c',
                                       '../../sph/shavite.c',
                                       '../../sph/simd.c',
                                       '../../sph/echo.c'],
                            include_dirs=['.', '../../sph'])

setup (name = 'x11_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by x11 hash',
       test_suite = 'test',
       ext_modules = [x11_hash_module])
