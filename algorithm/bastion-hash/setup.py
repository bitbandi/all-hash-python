from setuptools import setup, Extension

bastion_hash_module = Extension('bastion_hash',
                                sources = ['bastionmodule.c',
                                           'bastion.c',
                                           '../../sph/echo.c',
                                           '../../sph/hefty1.c',
                                           '../../sph/luffa.c',
                                           '../../sph/fugue.c',
                                           '../../sph/hamsi.c',
                                           '../../sph/hamsi_helper.c',
                                           '../../sph/skein.c',
                                           '../../sph/shabal.c',
                                           '../../sph/whirlpool.c'],
                                include_dirs=['.', '../../sph'])

setup (name = 'bastion_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [bastion_hash_module])
