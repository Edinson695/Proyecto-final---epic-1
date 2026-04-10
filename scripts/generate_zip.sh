#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "${script_dir}/.." && pwd)"
cd "${repo_root}"

project_name='prog3_pf_epic1_feature1_v2026_01'
output_zip="${project_name}.zip"
source_code=(
  include/utec/algebra/shape.h
  include/utec/algebra/tensor_backend.h
)

shopt -s nullglob
cpp_sources=(src/*.cpp)
shopt -u nullglob

if ((${#cpp_sources[@]} > 0)); then
  source_code+=("${cpp_sources[@]}")
else
  source_code+=(src)
fi

rm -f "${output_zip}"
zip -r "${output_zip}" "${source_code[@]}"

echo "Archivo generado: ${output_zip}"
