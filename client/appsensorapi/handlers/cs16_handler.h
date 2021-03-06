/*
  Copyright 2014 Google Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/
#ifndef GOOPY_APPSENSORAPI_HANDLERS_CS16_HANDLER_H__
#define GOOPY_APPSENSORAPI_HANDLERS_CS16_HANDLER_H__

#include "appsensorapi/common.h"
#include "appsensorapi/handler.h"
#include "base/logging.h"
#include "common/shellutils.h"

namespace ime_goopy {
namespace handlers {

class CS16Handler : public ime_goopy::Handler {
 public:
  CS16Handler() {
    version_info_.file_info[FileInfoKey::kProductName] =
        TEXT("Half-Life Launcher");
    version_info_.file_info[FileInfoKey::kOriginalFilename] =
        TEXT("hl.exe");
  }
  // Invokes any user-defined commands via this method.
  // data should be a pointer of bool.
  BOOL HandleCommand(uint32 command, void* data) const {
    switch (command) {
      case CMD_SHOULD_DISABLE_IME: {
        DCHECK(data);
        *(static_cast<bool*>(data)) = true;
        return TRUE;
      }
      default: {
        return FALSE;
      }
    }
    return FALSE;
  }
};
}  // namespace handlers
}  // namespace ime_goopy
#endif  // GOOPY_APPSENSORAPI_HANDLERS_CS16_HANDLER_H__
