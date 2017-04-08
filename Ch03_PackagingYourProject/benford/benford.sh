#!/bin/bash

for i in $(seq 1 9);
do
    grep -E "(^|[^1-9.])$i" ./*.c > "lines_with_${i}";
done
wc -l lines_with*
