// Set new default font family and font color to mimic Bootstrap's default styling
Chart.defaults.global.defaultFontFamily = 'Nunito', '-apple-system,system-ui,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,sans-serif';
Chart.defaults.global.defaultFontColor = '#858796';

const options = {
  maintainAspectRatio: true,
  elements: {
    point:{
        radius: 0
    }
  },
  layout: {
    padding: {
      left: 5,
      right: 5,
      top: 5,
      bottom: 5
    }
  },
  scales: {
    x: {
      type: 'time',
      time: {
          displayFormats: {
              quarter: 'MMM YYYY'
          }
      }
    },
    xAxes: [{
      time: {
        unit: 'date'
      },
      gridLines: {
        display: true,
        drawBorder: false
      },
      ticks: {
        maxTicksLimit: 10
      }
    }],
    yAxes: [{
      ticks: {
        maxTicksLimit: 20,
        padding: 1,
        // Include a dollar sign in the ticks
        // callback: function(value, index, values) {
        //   return '$' + number_format(value);
        // }
      },
      gridLines: {
        color: "rgb(234, 236, 244)",
        zeroLineColor: "rgb(234, 236, 244)",
        drawBorder: false,
        borderDash: [2],
        zeroLineBorderDash: [2]
      }
    }],  
  },
  tooltips: {
    backgroundColor: "rgb(255,255,255)",
    bodyFontColor: "#858796",
    titleMarginBottom: 10,
    titleFontColor: '#6e707e',
    titleFontSize: 14,
    borderColor: '#dddfeb',
    borderWidth: 1,
    xPadding: 15,
    yPadding: 15,
    displayColors: true,
    intersect: false,
    mode: 'index',
    caretPadding: 10,
    // callbacks: {
    //   label: function(tooltipItem, chart) {
    //     var datasetLabel = chart.datasets[tooltipItem.datasetIndex].label || '';
    //     return datasetLabel + ': $' + number_format(tooltipItem.yLabel);
    //   }
    // }
  }  
}

// function number_format(number, decimals, dec_point, thousands_sep) {
//   // *     example: number_format(1234.56, 2, ',', ' ');
//   // *     return: '1 234,56'
//   number = (number + '').replace(',', '').replace(' ', '');
//   var n = !isFinite(+number) ? 0 : +number,
//     prec = !isFinite(+decimals) ? 0 : Math.abs(decimals),
//     sep = (typeof thousands_sep === 'undefined') ? ',' : thousands_sep,
//     dec = (typeof dec_point === 'undefined') ? '.' : dec_point,
//     s = '',
//     toFixedFix = function(n, prec) {
//       var k = Math.pow(10, prec);
//       return '' + Math.round(n * k) / k;
//     };
//   // Fix for IE parseFloat(0.55).toFixed(0) = 0;
//   s = (prec ? toFixedFix(n, prec) : '' + Math.round(n)).split('.');
//   if (s[0].length > 3) {
//     s[0] = s[0].replace(/\B(?=(?:\d{3})+(?!\d))/g, sep);
//   }
//   if ((s[1] || '').length < prec) {
//     s[1] = s[1] || '';
//     s[1] += new Array(prec - s[1].length + 1).join('0');
//   }
//   return s.join(dec);
// }

function allZeros(array) {
  return array.every(item => item === 0 || item === "0.00");
}

function createDataset(label, color, data) {
  if (allZeros(data)) {
    return false;
  }
  
  return {
    label: label,
    tension: 0.4,
    fill: false,
    borderColor: color,
    data: data
  };
}

var co2Chart;
var o2Chart;

/**
 * 
 */
function ceateChart(elementName) {
  var element = document.getElementById(elementName);
  return new Chart(element, {
    type: 'line',
    data: {
      labels: [],
      datasets: [],
    },
    options: options
  });
}

function makeChart(values) {
  console.log(values);

  // create charts if needed
  if (co2Chart === undefined) {
    co2Chart = ceateChart("chartCO2");
  }
  if (o2Chart === undefined) {
    o2Chart = ceateChart("chartO2");
  }

  const colors = ['#4e73df', '#1cc88a', '#36b9cc', '#f6c23e', '#e74a3b', '#858796' ]
  
  const theLabels = values.map(function(d) {return new Date(d.timestamp)});

  const inputsCO2 = ['CO2_1', 'CO2_2', 'CO2_3', 'CO2_4', 'CO2_5', 'CO2_6']
  const datasets = inputsCO2
    .map((label, i) => {
      const data = values.map(function(d) {return d[label]});
      return createDataset(label, colors[i], data);
    })
    .filter(data => data !== false);

  co2Chart.data.labels = theLabels;
  co2Chart.data.datasets = datasets;
  co2Chart.update();

  const inputsO2 = ['O2_1', 'O2_2', 'O2_3', 'O2_4', 'O2_5', 'O2_6']
  const datasetsO2 = inputsO2
    .map((label, i) => {
      const data = values.map(function(d) {return d[label]});
      return createDataset(label, colors[i], data);
    })
    .filter(data => data !== false);

  o2Chart.data.labels = theLabels;
  o2Chart.data.datasets = datasetsO2;
  o2Chart.update();
}

function digitString2(digit) {
  return digit < 10 ? "0" + digit : digit;
}

function formatDate(date) {
  let month = digitString2(date.getMonth() + 1)
  let day = digitString2(date.getDate())
  let year = date.getFullYear()

  let hour = digitString2(date.getHours())
  let minutes = digitString2(date.getMinutes())

  return [year, month, day].join('-') + " " + [hour, minutes].join(":");
}

function refreshChartWithDelay(delayInHours) {
  let now = new Date();

  let untilElement = document.getElementById('datepickerUntil')
  untilElement.value = formatDate(now)

  let sinceElement = document.getElementById('datepickerSince')
  now.setHours(now.getHours() - delayInHours)
  sinceElement.value = formatDate(now)

  refreshChart()
}

function refreshChart(download = false) {

  let sample = document.getElementById('sample')
  let sinceElement = document.getElementById('datepickerSince')
  let untilElement = document.getElementById('datepickerUntil')

  // decide if it is grouped by minutes (reduce datapoints)
  var group = 0
  if ($('#group1m').is(':checked')) {
    group = 1
  } else if ($('#group2m').is(':checked')) {
    group = 2
  } else if ($('#group5m').is(':checked')) {
    group = 5
  } else if ($('#group10m').is(':checked')) {
    group = 10
  }

  console.log(group)

  var path = "";
  if (sinceElement.value !== "" && untilElement.value !== "") {
    path = `since=${sinceElement.value}&until=${untilElement.value}`
  } else if (sinceElement.value !== "") {
    path = `since=${sinceElement.value}`
  } else if (untilElement.value !== "") {
    path = `until=${untilElement.value}`
  }

  if (download) {
    path += "format=file"
  }

  if (group) {
    path += `&group=${group}`
  }

  if (sample !== null && sample.value) {
    path += `&sample=${sample.value}`
  }


  let uri = `https://bideko.elllimoner.com/index.php/sample/fetch?${path}`
  console.log(uri)

  if (download) {
    window.open(uri, '_blank').focus()
    return
  }

  d3.csv(uri)
    .then(makeChart)
}

refreshChart()
