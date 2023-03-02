FROM fedora:35
RUN  yum -y  install  dnf-plugins-core \
                      bc make ninja-build cmake binutils git wget diffutils file sed gawk grep which \
                      gcc-gfortran gcc-c++ clang bzip2   openssl-devel openssl \
                      libzip-devel  zlib zlib-devel pythia8-devel pythia8 \
                      valgrind HepMC HepMC-devel xz xz-devel bzip2 bzip2-devel zlib zlib-devel zlib-static libzstd-devel libzstd graphviz graphviz-devel pythia8 pythia8-devel  root \
                      protobuf protobuf-devel \
                      python3 python3-devel python2 python2-devel \
                      root-core root root-physics python3 python3-devel && yum -y clean all
