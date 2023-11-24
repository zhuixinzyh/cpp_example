cd build

for i in {1..20}
do
rm -rf *
done

set -e
cmake ..
make
./main