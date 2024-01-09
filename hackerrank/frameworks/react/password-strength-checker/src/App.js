import React from "react";
import './App.css';
import "h8k-components";
import PasswordChecker from "./components/PasswordChecker";

const title = "Password Strength Checker";

function App() {
  return (
    <div className="App">
      <h8k-navbar header={title}></h8k-navbar>
      <PasswordChecker />
    </div>
  );
}

export default App;
