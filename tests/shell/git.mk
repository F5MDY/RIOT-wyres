#######################################
# Git information
# Thanks to https://nullpointer.io/post/easily-embed-version-information-in-software-releases/
#######################################

ifneq (, $(shell which git))
GIT_VERSION := $(shell git --no-pager describe --tags --always)
GIT_COMMIT  := $(shell git rev-parse --verify HEAD)
GIT_DATE    := $(firstword $(shell git --no-pager show --date=iso-strict --format="%ad" --name-only))
BUILD_DATE  := $(shell date -u +"%Y-%m-%dT%H:%M:%SZ")

# If working tree is dirty, append dirty flag
ifneq ($(strip $(shell git status --porcelain 2>/dev/null)),)
 GIT_VERSION := $(GIT_VERSION)--dirty
endif
endif

GIT_DEFS = \
    -DGIT_VERSION=\"$(GIT_VERSION)\" \
    -DGIT_COMMIT=\"$(GIT_COMMIT)\" \
    -DGIT_DATE=\"$(GIT_DATE)\" \
    -DBUILD_DATE=\"$(BUILD_DATE)\"

CFLAGS += $(GIT_DEFS)
