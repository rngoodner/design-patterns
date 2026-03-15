#!/bin/bash
set -e

patterns=(strategy observer decorator factory-method abstract-factory command adapter facade template-method iterator composite state proxy)

run_one() {
    echo "=== $1 ==="
    ./build/"$1"
    echo
}

if [[ "${1}" == "-h" ]]; then
    echo "usage: ./run.sh [pattern]"
    echo
    echo "patterns: ${patterns[*]}"
    exit 0
elif [[ $# -eq 1 ]]; then
    run_one "$1"
else
    for p in "${patterns[@]}"; do
        run_one "$p"
    done
fi
