 // Connect to WebSocket bridge
  const ws = new WebSocket("ws://localhost:8080");

  ws.onopen = () => {
    console.log("WebSocket connected");
  };

  ws.onmessage = (event) => {
    try {
      const d = JSON.parse(event.data);

      updateUI({
        healthScore: d.health,
        state: d.state === 0 ? "HEALTHY"
              : d.state === 1 ? "DEGRADING"
              : "CRITICAL",
        confidence: d.confidence,
        updateScore: 0,
        diagnosis: "Electrical behavior anomaly analysis",
        recommendation: "Monitoring voltage stability"
      });

    } catch (e) {
      console.error("Invalid JSON:", event.data);
    }
  };

  ws.onerror = (err) => {
    console.error("WebSocket error", err);
  };

        // Update UI with data
        function updateUI(data) {
            // Update health score
            const scoreValue = document.getElementById('scoreValue');
            const scoreRing = document.getElementById('scoreRing');
            const scoreUpdate = document.getElementById('scoreUpdate');
            
            scoreValue.textContent = data.healthScore;
            
            // Update score change indicator
            const updateText = data.updateScore > 0 ? `+${data.updateScore}` : data.updateScore.toString();
            scoreUpdate.textContent = updateText;
            scoreUpdate.style.color = data.updateScore > 0 ? '#4caf50' : data.updateScore < 0 ? '#f44336' : '#7d8694';
            scoreUpdate.style.borderColor = scoreUpdate.style.color;
            
            // Trigger animation
            scoreUpdate.style.animation = 'none';
            setTimeout(() => {
                scoreUpdate.style.animation = 'slideIn 0.5s ease';
            }, 10);

            // Update state badge
            const stateBadge = document.getElementById('stateBadge');
            stateBadge.textContent = data.state;
            stateBadge.className = 'state-badge';
            
            // Apply state-specific styling
            let stateClass, scoreColor;
            switch(data.state) {
                case 'HEALTHY':
                    stateClass = 'state-healthy';
                    scoreColor = '#4caf50';
                    break;
                case 'DEGRADING':
                    stateClass = 'state-degrading';
                    scoreColor = '#ff9800';
                    break;
                case 'CRITICAL':
                    stateClass = 'state-critical';
                    scoreColor = '#f44336';
                    break;
            }
            
            stateBadge.classList.add(stateClass);
            scoreValue.style.color = scoreColor;
            scoreRing.style.borderColor = scoreColor;
            scoreRing.style.boxShadow = `0 0 40px ${scoreColor}40, inset 0 0 40px rgba(0, 0, 0, 0.3)`;

            // Update confidence
            document.getElementById('confidenceValue').textContent = `${data.confidence}%`;

            // Update diagnosis
            const diagnosisCard = document.getElementById('diagnosisCard');
            const diagnosisText = document.getElementById('diagnosisText');
            diagnosisText.textContent = data.diagnosis;
            diagnosisCard.style.borderLeftColor = scoreColor;

            // Update recommendation
            const recommendationCard = document.getElementById('recommendationCard');
            const recommendationText = document.getElementById('recommendationText');
            recommendationText.textContent = data.recommendation;
            recommendationCard.style.borderLeftColor = scoreColor;
        }
 