#!/bin/bash

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
