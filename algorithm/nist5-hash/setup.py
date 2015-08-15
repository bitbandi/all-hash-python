from setuptools import setup, Extension

nist5_hash_module = Extension('nist5_hash',
                              sources = ['nist5module.c',
                                         'nist5.c',
                                         '../../sph/blake.c',
                                         '../../sph/groestl.c',
                                         '../../sph/jh.c',
                                         '../../sph/keccak.c',
                                         '../../sph/skein.c'],
                              include_dirs=['.', '../../sph'])

setup (name = 'nist5_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by Talkcoin',
       test_suite = 'test',
       ext_modules = [nist5_hash_module])
