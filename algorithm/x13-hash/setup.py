from setuptools import setup, Extension

x13_hash_module = Extension('x13_hash',
                            sources = ['x13module.c',
                                       'x13.c',
                                       '../../sph/blake.c',
                                       '../../sph/bmw.c',
                                       '../../sph/groestl.c',
                                       '../../sph/jh.c',
                                       '../../sph/keccak.c',
                                       '../../sph/skein.c',
                                       '../../sph/cubehash.c',
                                       '../../sph/echo.c',
                                       '../../sph/luffa.c',
                                       '../../sph/simd.c',
                                       '../../sph/hamsi.c',
                                       '../../sph/hamsi_helper.c',
                                       '../../sph/fugue.c',
                                       '../../sph/shavite.c'],
                            include_dirs=['.', '../../sph'])

setup (name = 'x13_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by x13 hash',
       test_suite = 'test',
       ext_modules = [x13_hash_module])
