document.addEventListener('DOMContentLoaded',function(){
    let incorrecta = document.querySelectorAll('.incorrect');

for (let i = 0; i < incorrecta.length; i++)
{
    incorrecta[i].addEventListener('click', function(){
        incorrecta[i].style.backgroundColor = 'red';
        document.querySelector("#answer").innerHTML = "incorrect!";
    });
}

let correct = document.querySelector('.correct');
correct.addEventListener('click', function(){
    correct.style.backgroundColor = "green";
    document.querySelector("#answer").innerHTML = "correct!";
});

let submitted = document.querySelector('.submitbutton');
submitted.addEventListener('click', function(){
    let correctanswer = document.querySelector(".optanswer");
    if (correctanswer.value == 'nature') {
        correctanswer.style.backgroundColor = "green";
        document.querySelector("#correctanswer").innerHTML = "correct!";
    }
    else {
        correctanswer.style.backgroundColor = "red";
        document.querySelector("#correctanswer").innerHTML = "incorrect!";
    }
});
});

