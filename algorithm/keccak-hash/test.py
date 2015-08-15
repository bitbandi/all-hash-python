from unittest import TestCase
import urlparse
import keccak_hash
import weakref
import binascii
import StringIO

from binascii import unhexlify


class Test(TestCase):

    def test_powhash(self):
        teststart = '700000005d385ba114d079970b29a9418fd0549e7d68a95c7f168621a314201000000000578586d149fd07b22f3a8a347c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000';
        testbin = unhexlify(teststart)
        hash_bin = keccak_hash.getPoWHash(testbin)
        self.assertEqual(hash_bin, unhexlify('de96b224d0cbb2632c16b9ce311dfbabc10d155c2f4f9883eb345e991e82ac9b'))
