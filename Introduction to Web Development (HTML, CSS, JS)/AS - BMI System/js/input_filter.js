function setInputFilter(textbox, inputFilter) {
    ["input", "keydown", "keyup", "mousedown", "mouseup", "select", "contextmenu", "drop"].forEach(function(event) {
      textbox.addEventListener(event, function() {
        if (inputFilter(this.value)) {
          this.oldValue = this.value;
          this.oldSelectionStart = this.selectionStart;
          this.oldSelectionEnd = this.selectionEnd;
        } else if (this.hasOwnProperty("oldValue")) {
          this.value = this.oldValue;
          this.setSelectionRange(this.oldSelectionStart, this.oldSelectionEnd);
        } else {
          this.value = "";
        }
        });
    });
}

setInputFilter(document.getElementById("height"), function(value) {
  return /^-?\d*[.]?\d{0,2}$/.test(value); });

setInputFilter(document.getElementById("weight"), function(value) {
  return /^-?\d*[.]?\d{0,2}$/.test(value); });
  
setInputFilter(document.getElementById("body_fat"), function(value) {
  return /^-?\d*[.]?\d{0,2}$/.test(value); });