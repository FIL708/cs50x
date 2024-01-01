const firstPrompt = document.querySelector("#first-prompt");
const firstQuestionButtons = document.querySelectorAll(".first-answer");

const secondPrompt = document.querySelector("#second-prompt");
const secondQuestionSumbit = document.querySelector(".secound-submit");
const secondQuestionInput = document.querySelector(".second-input")

const usePrompt = (element, type) => {
    if (type === "correct") {
        element.classList.add("correct-prompt");
        element.innerHTML = "Correct!";
    } else if (type === "wrong") {
        element.classList.add("wrong-prompt");
        element.innerHTML = "Incorrect!"
    }
}

const checkFirst = (event) => {
    if (event.target.name === "react") {
        event.target.classList.add("correct");
        usePrompt(firstPrompt, "correct");
    } else {
        event.target.classList.add("wrong")
        usePrompt(firstPrompt, "wrong");
    }

    firstQuestionButtons.forEach(button => {
        button.disabled = true;
    })
}

const checkSecond = (event) => {
    event.preventDefault();
    if (secondQuestionInput.value.toLowerCase() === "function") {
        secondQuestionInput.classList.add("correct");
        usePrompt(secondPrompt, "correct");
    } else {
        secondQuestionInput.classList.add("wrong");
        usePrompt(secondPrompt, "wrong");
    }
    secondQuestionSumbit.disabled = true;
    secondQuestionInput.disabled = true;
}

firstQuestionButtons.forEach(button => {
    button.addEventListener("click", checkFirst)
});

secondQuestionSumbit.addEventListener("click", checkSecond);
