document.getElementById("counter-button").onclick = () => {
    let spanElement = document.getElementById("counter-value");
    spanElement.textContent = (parseInt(spanElement.textContent) + 1).toString();
};