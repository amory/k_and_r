#!/bin/bash

echo -n ""   | ./word_count
echo "a"     | ./word_count
echo " a"    | ./word_count
echo "a "    | ./word_count
echo " a "   | ./word_count
echo " a b"  | ./word_count
echo " a b " | ./word_count
