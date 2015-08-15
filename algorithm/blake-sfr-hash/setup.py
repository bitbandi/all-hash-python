from setuptools import setup, Extension

blake_sfr_hash_module = Extension('blake_sfr_hash',
                                  sources = ['blake_sfrmodule.c',
                                             'blake_sfr.c',
                                             '../../sph/blake.c'],
                                  include_dirs=['.', '../../sph'])

setup (name = 'blake_sfr_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [blake_sfr_hash_module])
