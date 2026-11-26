# AGENTS.md

Guidance for automated coding agents working in this repository.

This file does not replace the project documentation. The Markdown files
listed below are authoritative; read the relevant ones before making
changes. If anything here seems to conflict with them, follow those files.

## Project documentation

- [README.md](README.md): project overview, compatibility and deprecation notes.
- [DEVELOPMENT.md](DEVELOPMENT.md): coding rules, naming conventions,
  formatting, comment style, commit and merge-request policy, release checklist.
- [SRCPKG.md](SRCPKG.md): layout of the source tree.
- [SRCINSTALL.md](SRCINSTALL.md): building from source, CMake options, running tests.
- [PKGINSTALL.md](PKGINSTALL.md): pre-built packages.
- [EXAMPLES.md](EXAMPLES.md): building and running the examples.
- [STANDARDS.md](STANDARDS.md): event-coding standards (graph structure,
  particle IDs, status codes, weights).
- [CHANGELOG.md](CHANGELOG.md): change log (Keep a Changelog format).
- [AUTHORS.md](AUTHORS.md), [LICENCE.md](LICENCE.md): authorship and licence.

## Working conservatively

- Keep changes small and limited to what was asked. Do not refactor,
  reformat or rename unrelated code.
- Follow the conventions in [DEVELOPMENT.md](DEVELOPMENT.md) exactly,
  including the no-throw policy, the `HEPMC3_ERROR`/`HEPMC3_WARNING`/
  `HEPMC3_DEBUG` macros for output, and Doxygen-style documentation.
- Do not run `make beauty`, `make beautypython` or other repository-wide
  formatting unless asked; it touches many files.
- Do not change I/O formats, public API or ABI without explicit
  instruction. See the compatibility notes in [README.md](README.md).
- Do not hand-edit bundled third-party code (`pybind11`, `bxzstr`) or the
  automatically generated Python binding sources described in
  [SRCPKG.md](SRCPKG.md). Do not regenerate the bindings with `binder`
  unless asked.
- Do not change version numbers, tags or release metadata unless asked.
- Do not commit or push unless asked. Direct pushes to `master` are not
  allowed; contributions go through merge requests (see
  [DEVELOPMENT.md](DEVELOPMENT.md)).
- When a change is user-visible or technical, propose a
  [CHANGELOG.md](CHANGELOG.md) entry in the existing style.

## Building and testing

Use an out-of-source build directory and the CMake options described in
[SRCINSTALL.md](SRCINSTALL.md). Tests are enabled with
`-D HEPMC3_ENABLE_TEST=ON` and run with `ctest`. Optional components
(ROOT I/O, Python bindings, search, protobuf I/O) need their external
dependencies; disable the ones that are not available rather than
modifying the build system to work around them.

Report test results as they are; do not modify or disable tests to make
them pass.
