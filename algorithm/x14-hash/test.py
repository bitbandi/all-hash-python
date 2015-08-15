from unittest import TestCase
import urlparse
import x14_hash
import weakref
import binascii
import StringIO

from binascii import unhexlify


class Test(TestCase):

    def test_powhash(self):
        teststart = '700000005d385ba114d079970b29a9418fd0549e7d68a95c7f168621a314201000000000578586d149fd07b22f3a8a347c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000';
        testbin = unhexlify(teststart)
        hash_bin = x14_hash.getPoWHash(testbin)
        self.assertEqual(hash_bin, unhexlify('123d785cd8a76cb07fc2367deda34788ef19a32447f021b136091d221d01b7a6'))
