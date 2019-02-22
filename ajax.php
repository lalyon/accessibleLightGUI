<?php
if (isset($_POST['action'])) {
    switch ($_POST['action']) {
        case 'red':
            red();
            break;
        case 'blue':
            blue();
            break;
        case 'green':
            green();
            break;

        case 'orange':
            orange();
            break;

        case 'yellow':
            yellow();
            break;

        case 'navy':
            navy();
            break;

        case 'pink':
            pink();
            break;

        case 'forestgreen':
          forestgreen();
          break;

        case 'babyblue':
          babyblue();
          break;

        case 'salmon':
          salmon();
          break;

        case 'hotpink':
          hotpink();
          break;

        case 'mintgreen':
          mintgreen();
          break;
    }

}

function red() {
    exec("python red.py");
    exit;
}

function blue() {
  exec("python blue.py");
  exit;
}

function green() {
  exec("python green.py");
  exit;
}

function orange() {
  exec("python orange.py");
  exit;
}

function yellow() {
  exec("python yellow.py");
  exit;
}

function navy() {
  exec("python navy.py");
  exit;
}

function pink() {
  exec("python pink.py");
  exit;
}

function forestgreen() {
  exec("python forestgreen.py");
  exit;
}

function babyblue() {
  exec("python babyblue.py");
  exit;
}

function salmon() {
  exec("python salmon.py");
  exit;
}

function hotpink() {
  exec("python hotpink.py");
  exit;
}

function mintgreen() {
  exec("python mintgreen.py");
  exit;
}
?>
