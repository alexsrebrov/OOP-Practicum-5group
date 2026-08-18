async function loadWeeks() {
  const response = await fetch("weeks.json");

  if (!response.ok) {
    throw new Error("Could not load weeks.json");
  }

  return await response.json();
}

function startPresentation(path) {
  document.getElementById("week-selector").style.display = "none";

  remark.create({
    sourceUrl: path,
    ratio: "16:9",
    highlightStyle: "magula",
    highlightLines: true,
    countIncrementalSlides: false,
  });
}

async function init() {
  const weeks = await loadWeeks();

  const select = document.getElementById("week");
  const button = document.getElementById("start");

  weeks.forEach((week) => {
    const option = document.createElement("option");

    option.value = week.path;
    option.textContent = week.name;

    select.appendChild(option);
  });

  const params = new URLSearchParams(window.location.search);
  const selectedWeek = params.get("week");

  if (selectedWeek) {
    startPresentation(selectedWeek);
    return;
  }

  button.addEventListener("click", () => {
    const path = select.value;

    window.location.href = `?week=${encodeURIComponent(path)}`;
  });
}

init().catch((error) => {
  console.error(error);

  document.getElementById("error").textContent =
    "Неуспешно зареждане на темите.";
});
