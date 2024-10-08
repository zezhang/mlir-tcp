//===------------------------------------------------------------*- C++ -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// Also available under a BSD-style license. See LICENSE.
//
//===----------------------------------------------------------------------===//

#include "mlir-tcp/InitAll.h"

#include "mlir-tcp/Conversion/Passes.h"
#include "mlir-tcp/Dialect/IR/TcpDialect.h"
#include "mlir-tcp/Dialect/IR/TcpTilingInterfaceImpl.h"
#include "mlir-tcp/Dialect/Transforms/Passes.h"

#include "mlir/Dialect/Func/Extensions/InlinerExtension.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Dialect.h"
#include "torch-mlir/Dialect/Torch/IR/TorchDialect.h"
#include "torch-mlir/Dialect/TorchConversion/IR/TorchConversionDialect.h"

void mlir::tcp::registerAllDialects(mlir::DialectRegistry &registry) {
  registry.insert<tcp::TcpDialect>();
  registry.insert<torch::Torch::TorchDialect>();
  registry.insert<torch::TorchConversion::TorchConversionDialect>();
  mlir::func::registerInlinerExtension(registry);
  mlir::tcp::registerTilingInterfaceExternalModels(registry);
}

void mlir::tcp::registerAllPasses() {
  mlir::tcp::registerTcpConversionPasses();
  mlir::tcp::registerTcpDialectPasses();
}
