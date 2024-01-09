import React from "react";

const PasswordStrength = (props) => {
    const hasUppercase = (password) => {
        return /[A-Z]/.test(password);
    };

    const hasLowercase = (password) => {
        return /[a-z]/.test(password);
    };

    const hasNumber = (password) => {
        return /[0-9]/.test(password);
    };

    const hasSpecialCharacter = (password) => {
        return /[!-/]/.test(password)
            || /[:-@]/.test(password)
            || /[[-`]/.test(password)
            || /[{-~]/.test(password);
    };

    const hasMinimumLength = (password) => {
        return password.length >= 8;
    }

    const getNumCharacteristics = (password) => {
        let numCharacteristics = 0;
        if (hasUppercase(password)) {
            ++numCharacteristics;
        }
        if (hasLowercase(password)) {
            ++numCharacteristics;
        }
        if (hasNumber(password)) {
            ++numCharacteristics;
        }
        if (hasSpecialCharacter(password)) {
            ++numCharacteristics;
        }
        if (hasMinimumLength(password)) {
            ++numCharacteristics;
        }
        return numCharacteristics;
    };

    const getValue = (password, values) => {
        let numCharacteristics = getNumCharacteristics(password);
        if (numCharacteristics > 2) {
            if (numCharacteristics == 5) {
                return values[0];
            } else {
                return values[1];
            }
        } else {
            return values[2];
        }
    };

    return (
        <div
            className="px-5 py-5"
            style={{
                backgroundColor: getValue(props.password,
                    ["green", "orange", "red"]),
            }}
            data-testid="passwordStrengthDiv"
        >
            <h4
                style={{
                    color: "white",
                    textAlign: "center",
                }}
            >
                {getValue(props.password,
                    ["Strong", "Moderate", "Weak"])} Password
            </h4>
        </div>
    );
};

export default PasswordStrength;