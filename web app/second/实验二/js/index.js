window.onload = () => {
    rem()
    window.onresize = () => {
        rem()
    }

}
function rem() {
    let idealViewWidth = document.documentElement.clientWidth || document.body.clientWidth;
    const basicvalue = 828; //设计稿尺寸
    document.documentElement.style.fontSize = (idealViewWidth / basicvalue) * 100 + 'px';
}