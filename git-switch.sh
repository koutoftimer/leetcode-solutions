#!/bin/bash

[[ $# == 0 ]] && echo "Usage sh $0 <name of the problem>" && exit 1

title="$@"
title="${title// /-}"
title="${title//./}"
branch=$(git branch | cut --delimiter=' ' --fields=2)

printf "Switching from '$branch' to '$title'\nConfirm [y/N] "
read input
case "$input" in
        [Yy]) ;;
        *) exit 1 ;;
esac

git switch -c "$title" master
