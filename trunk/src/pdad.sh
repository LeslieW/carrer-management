#!/bin/bash

###############################################################################
#
#	pdad.sh
#
#	A small daemon that periodically sweeps an input directory,
#	looking for input files (employees CSV data) to process.
#	Uses the conv and app applications to this end.
#
#	Created at:
#		2012-01-11
#
#	Author(s):
#
#		B5-8 LAPRIII group
#
###############################################################################

PDAD_HOME=`pwd`
BIN_DIR=$PDAD_HOME
INPUT_DIR=../tests
OUTPUT_DIR=$PDAD_HOME
LOG_FILE=$OUTPUT_DIR/pdad_log
SLEEP=1

while [[ 1 -eq 1 ]]
do
	sleep($SLEEP)
	
	file_list=`ls $INPUT_DIR/*.csv`
	for file in $file_list
	do
		$BIN_DIR/conv $file $file_`date +%Y-%m-%d`.bin
		RET=$?
		
		if [[ $RET -ne 0 ]]
		then
			echo "conv failed for file $file" >> pdad_log_`date +%Y%m%d_%H%M%S`
		fi
	done
done