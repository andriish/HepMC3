FROM archlinux:latest
RUN  pacman -Syu --noconfirm \
                      bc make  cmake binutils git wget  file sed gawk grep which  \
                      pkgconf  root protobuf   \
                      gcc gcc-fortran clang  \
                      libzip  hdf5  ccache  && pacman -Scc --noconfirm
