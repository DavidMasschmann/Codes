function get_patient_from_form (form) {
    let patient = {
        name: form.name.value,
        weight: form.weight.value,
        height: form.height.value,
        body_fat: form.body_fat.value,
        bmi: bmi_calculator(form.weight.value, form.height.value)
    }

    return patient;
}

function assemble_tr (patient) {
    let patient_tr = document.createElement("tr");
    patient_tr.classList.add("patient");

    patient_tr.append(
        assemble_td(patient.name, "name_info"),
        assemble_td(patient.weight, "weight_info"),
        assemble_td(patient.height, "height_info"),
        assemble_td(patient.body_fat, "bodyFat_info"),
        assemble_td(patient.bmi, "bmi_info")
    );

    return patient_tr;
}

function assemble_td (info, html_class) {
    let td = document.createElement("td");
    td.classList.add(html_class);
    td.textContent = info;

    return td;
}

function patient_validation(patient) {
    let errors = [];

    if (patient.name.length == 0) {
        errors.push("Name field can't be blank");
    }

    if (patient.body_fat.length == 0) {
        errors.push("Body Fat field can't be blank");
    }

    if (patient.weight.length == 0) {
        errors.push("Weight field can't be blank");
    }

    if (patient.height.length == 0) {
        errors.push("Height field can't be blank");
    }

    if (!height_validation(patient.height)) {
        errors.push("Height is invalid");
    }

    if (!weight_validation(patient.weight)) {
        errors.push("Weight is invalid");
    }

    return errors;
}

function show_error_message(errors) {
    let ul = document.querySelector("#error-messages");
    ul.innerHTML = "";

    errors.forEach(function(error) {
        let li = document.createElement("li");
        li.textContent = error;
        ul.append(li);
    });
}

let add_button = document.querySelector("#add_patient");

add_button.addEventListener("click", function(){
    event.preventDefault();
    console.log("Click");

    let table = document.querySelector("#patients_table");
    let form = document.querySelector("#form");

    let patient = get_patient_from_form(form);

    let patient_tr = assemble_tr(patient);

    let errors = patient_validation(patient);

    if (errors.length > 0) {
        show_error_message(errors);
        return;
    }

    table.append(patient_tr);

    form.reset();
    let error_messages = document.querySelector("#error-messages");
    error_messages.innerHTML = "";
});
