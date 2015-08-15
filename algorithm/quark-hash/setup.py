from setuptools import setup, Extension

quark_hash_module = Extension('quark_hash',
                              sources = ['quarkmodule.c',
                                         'quark.c',
                                         '../../sph/blake.c',
                                         '../../sph/bmw.c',
                                         '../../sph/groestl.c',
                                         '../../sph/jh.c',
                                         '../../sph/keccak.c',
                                         '../../sph/skein.c'],
                              include_dirs=['.', '../../sph'])

setup (name = 'quark_hash',
       version = '1.0',
       description = 'Bindings for scrypt proof of work used by Quarkcoin',
       test_suite = 'test',
       ext_modules = [quark_hash_module])
