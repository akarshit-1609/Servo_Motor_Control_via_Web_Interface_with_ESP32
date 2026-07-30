function sendata(d){
    fetch("/degree", {
        method: "POST",
        headers: {
            'Accept': 'text/plain',
            'Content-Type': 'text/plain'
        },
        body: d
    }).then(res => {
        return res.text();
    }).then(b => {

    }).catch(e => {
        
    });
}

const body = document.body;
const image = document.getElementById('rotate-image');
var degree = document.getElementById("range");
var output = document.getElementById("output");
var angle = "0";

degree.addEventListener("touchstart", (e) => {
    degree.style.opacity = "1";
});

degree.addEventListener("touchmove", (e) => {
    angle = String(degree.value);
    output.innerHTML = angle + "<sup>0</sup> degree";
    image.style.transform = `rotate(${-1*parseInt(angle)}deg)`;
});

degree.addEventListener("touchend", (e) => {
    degree.style.opacity = "0.7";
    angle = String(degree.value);
    output.innerHTML = angle + "<sup>0</sup> degree";
    image.style.transform = `rotate(${-1*parseInt(angle)}deg)`;
    sendata("data=" + angle);
});

function rf() {
    body.requestFullscreen();
}