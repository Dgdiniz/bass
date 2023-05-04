
auto Bass::addDiagnostic(const string& s) -> bool {
  if (activeInstruction) {
    auto& i = *activeInstruction;

    //Change quotes to avoid JSON parsing errors
    string s2 = s;
    for (auto& c : s2) {
      if (c == '"') c = '\'';
    }

    if (numberOfDiagnostics++ > 0) diagnostics.append(",");
    diagnostics.append("{\"severity\": 2, \"range\": { \"start\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": ");
    diagnostics.append(i.statementOffset);
    diagnostics.append(" }, \"end\": { \"line\": ");
    diagnostics.append(i.lineNumber - 1);
    diagnostics.append(", \"character\": ");
    diagnostics.append(i.statementOffset + i.statement.size());
    diagnostics.append("} }, \"message\": \"");
    diagnostics.append(s2);
    diagnostics.append("\", \"source\": \"");
    diagnostics.append(sourceFilenames[i.fileNumber]);
    diagnostics.append("\" }");
  }
  return true;
}
