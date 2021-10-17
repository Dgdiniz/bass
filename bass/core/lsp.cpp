
auto Bass::addDiagnostic(const string& s) -> bool {
  if (activeInstruction) {
    auto& i = *activeInstruction;

    if (numberOfDiagnostics++ > 0) diagnostics.append(",");
    diagnostics.append("{\"severity\": 2, \"range\": { \"start\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": 0}, \"end\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": ");
    diagnostics.append(i.statement.size());
    diagnostics.append("} }, \"message\": \"");
    diagnostics.append(s);
    diagnostics.append("\", \"source\": \"");
    diagnostics.append(sourceFilenames[i.fileNumber]);
    diagnostics.append("\" }");
  }
  return true;
}
