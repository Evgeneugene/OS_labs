mkdir -p {lofsdisk/bin,lofsdisk/lib64,lofsdisk/usr/lib,lofsdisk/usr/lib64}
cp /bin/bash lofsdisk/bin
ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
cp lofsdisk/usr/lib/* lofsdisk/lib
cp lofsdisk/usr/lib64/* lofsdisk/lib64
echo file1 > lofsdisk/file1
echo file2 > lofsdisk/file2
gcc ex2.c -o ex2
cp ex2 lofsdisk
sudo chroot lofsdisk /ex2 > ex2.txt
./ex2 >> ex2.txt
