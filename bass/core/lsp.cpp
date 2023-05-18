
auto Bass::addDiagnostic(string& s, Instruction* instruction) -> bool {
  if ((activeInstruction) || (instruction)) {
    auto& i = (activeInstruction) ? *activeInstruction : *instruction;

    if (numberOfDiagnostics >= 1000) return true;

    // Replace \ with \\ to avoid JSON parsing errors
    s.replace("\\", "\\\\");
    //Change quotes to avoid JSON parsing errors
    s.replace("\"", "\\\"");
    
    if (numberOfDiagnostics++ > 0) diagnostics.append(",");
    diagnostics.append("{\"severity\": 1, \"range\": { \"start\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": ");
    diagnostics.append(i.statementOffset);
    diagnostics.append(" }, \"end\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": ");
    diagnostics.append(i.statementOffset + i.rawStatement.strip().size());
    diagnostics.append("} }, \"message\": \"");
    diagnostics.append(s);
    diagnostics.append("\", \"source\": \"");
    diagnostics.append(sourceFilenames[i.fileNumber]);
    diagnostics.append("\" }");
  }

  return true;
}
