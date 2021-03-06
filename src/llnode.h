#ifndef SRC_LLNODE_H_
#define SRC_LLNODE_H_

#include <string>

#include <lldb/API/LLDB.h>

#include "src/llv8.h"

namespace llnode {

class CommandBase : public lldb::SBCommandPluginInterface {
 public:
  char** ParseInspectOptions(char** cmd, v8::Value::InspectOptions* options);
};

class BacktraceCmd : public CommandBase {
 public:
  BacktraceCmd(v8::LLV8* llv8) : llv8_(llv8) {}
  ~BacktraceCmd() override {}

  bool DoExecute(lldb::SBDebugger d, char** cmd,
                 lldb::SBCommandReturnObject& result) override;

 private:
  v8::LLV8* llv8_;
};

class PrintCmd : public CommandBase {
 public:
  PrintCmd(v8::LLV8* llv8, bool detailed) : llv8_(llv8), detailed_(detailed) {}

  ~PrintCmd() override {}

  bool DoExecute(lldb::SBDebugger d, char** cmd,
                 lldb::SBCommandReturnObject& result) override;

 private:
  v8::LLV8* llv8_;
  bool detailed_;
};

class ListCmd : public CommandBase {
 public:
  ListCmd(v8::LLV8* llv8) : llv8_(llv8) {}
  ~ListCmd() override {}

  bool DoExecute(lldb::SBDebugger d, char** cmd,
                 lldb::SBCommandReturnObject& result) override;

 private:
  v8::LLV8* llv8_;
};

}  // namespace llnode

#endif  // SRC_LLNODE_H_
