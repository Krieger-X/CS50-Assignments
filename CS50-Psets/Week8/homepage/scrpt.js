//variables for hidden content
var hiddenContent = [
    document.getElementById("myText"),
    document.getElementById("myText1"),
    document.getElementById("myImg")
];

var button = document.getElementById("myButton");
var currentContent = -1;

//Annoying alert when each time page gets refreshed
document.addEventListener("DOMContentLoaded", function() {
    alert("Welcome to my homepage!")
});

//show the content one by one
button.addEventListener("click", function() {
    currentContent = (currentContent + 1) % hiddenContent.length;
    hiddenContent.forEach(content => content.style.display = "none");
    hiddenContent[currentContent].style.display = "block";
});
