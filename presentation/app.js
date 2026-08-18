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
        countIncrementalSlides: false
    });
}

async function init() {
    const weeks = await loadWeeks();
    const container = document.getElementById("weeks");

    weeks.forEach(week => {
        const card = document.createElement("button");

        card.className = "week-card";

        card.innerHTML = `
            <span class="week-number">
                ${week.name}
            </span>

            <span class="week-action">
                Презентация →
            </span>
        `;

        card.addEventListener("click", () => {
            startPresentation(week.path);
        });

        container.appendChild(card);
    });
}

init().catch(error => {
    console.error(error);

    document.getElementById("error").textContent =
        "Неуспешно зареждане на темите.";
});