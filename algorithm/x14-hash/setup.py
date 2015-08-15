from setuptools import setup, Extension

x14_hash_module = Extension('x14_hash',
                            sources = ['x14module.c',
                                       'x14.c',
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
                                       '../../sph/shabal.c',
                                       '../../sph/shavite.c'],
                            include_dirs=['.', '../../sph'])

setup (name = 'x14_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by x14 hash',
       test_suite = 'test',
       ext_modules = [x14_hash_module])
