import React, { useState } from 'react';
import PasswordStrength from "./PasswordStrength";

const PasswordChecker = () => {
    const [inputType, setInputType] = useState("password");
    const [password, setPassword] = useState("");

    const onShow = () => {
        setInputType(inputType === "password" ? "text" : "password");
    };

    const onClear = () => {
        setPassword("");
    };

    const handleChange = (e) => {
        setPassword(e.target.value);
    };

    return (
        <div className="layout-column align-items-center justify-content-center pu-40 mt-100">
            <div className="card w-50 px-75 py-30">
                <form onSubmit={(e) => e.preventDefault()}>
                    <h2>Enter Your Password</h2>
                    <div className="layout-column mb-10">
                        <input
                            type={inputType}
                            id="name"
                            placeholder="Enter Password"
                            data-testid="passwordInput"
                            value={password}
                            onChange={handleChange}
                        />
                    </div>
                </form>
                <div className="py-10" data-testid="buttonDiv">
                    <button onClick={onShow}>Show Password</button>
                    <button onClick={onClear}>Clear Password</button>
                </div>
            </div>
            <div className="w-50 py-20">
                <PasswordStrength password={password} />
            </div>
        </div>
    );
};

export default PasswordChecker;
